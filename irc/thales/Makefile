PORTNAME=	thales
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	irc
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC to MySQL gateway

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/ircd:irc/ircd-hybrid

USES=		gmake mysql shebangfix
SHEBANG_FILES=	examples/MRTG/thalesinfo.pl
USE_RC_SUBR=	thales

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ircd=hybrid \
		--prefix=${PREFIX}/sbin/thales \
		--with-mysql=${LOCALBASE} \
		--with-mysql-libraries=${LOCALBASE}/lib/mysql

OPTIONS_DEFINE=	MODES DOCS EXAMPLES
OPTIONS_DEFAULT=MODES
MODES_DESC=		Support modes in the database

MODES_CONFIGURE_OFF=	--enable-no-modes

post-patch: .SILENT
	${FIND} -d ${WRKSRC} -type d -name CVS -exec ${RM} -r {} \;
	${REINPLACE_CMD} -e 's,thales.conf,${PREFIX}/etc/&,' \
		${WRKSRC}/src/conf.h
# Fix the build with -fno-common (for Clang 11 and GCC 10)
	${REINPLACE_CMD} -e '/total_read, total_written/s,^,extern ,' \
		${WRKSRC}/src/sockutil.h

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/thales ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/data/thales.conf.default ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/data/*.sql ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DATADIR}/tools
	${CP} -r ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/tools/* ${STAGEDIR}${DATADIR}/tools

.include <bsd.port.mk>
