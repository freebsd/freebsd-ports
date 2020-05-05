# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	thales
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	irc
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Thales -- An IRC to MySQL gateway

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake mysql shebangfix
SHEBANG_FILES=	examples/MRTG/thalesinfo.pl
USE_RC_SUBR=	thales

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ircd=${_IRCD} \
		--prefix=${PREFIX}/sbin/thales \
		--with-mysql=${LOCALBASE} \
		--with-mysql-libraries=${LOCALBASE}/lib/mysql

OPTIONS_DEFINE=	MODES DOCS EXAMPLES
OPTIONS_RADIO=	IRCD
OPTIONS_RADIO_IRCD=	HYBRID UNREAL
OPTIONS_DEFAULT=MODES UNREAL
MODES_DESC=		Support modes in the database
HYBRID_DESC=	Build for ircd-hybrid
UNREAL_DESC=	Build for unreal ircd

MODES_CONFIGURE_OFF=	--enable-no-modes
HYBRID_RUN_DEPENDS=	${LOCALBASE}/bin/ircd:irc/ircd-hybrid
HYBRID_VARS=		_IRCD=hybrid IS_INTERACTIVE=yes
UNREAL_RUN_DEPENDS=	${LOCALBASE}/libexec/ircd:irc/unreal
UNREAL_VARS=		_IRCD=unreal

post-patch: .SILENT
	${FIND} -d ${WRKSRC} -type d -name CVS -exec ${RM} -r {} \;
	${REINPLACE_CMD} -e 's,thales.conf,${PREFIX}/etc/&,' \
		${WRKSRC}/src/conf.h

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/thales ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/data/thales.conf.default ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/data/*.sql ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DATADIR}/tools
	${CP} -r ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	${CP} -r ${WRKSRC}/tools/* ${STAGEDIR}${DATADIR}/tools

.include <bsd.port.mk>
