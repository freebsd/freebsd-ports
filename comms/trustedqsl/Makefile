# New ports collection makefile for:   TrustedQSL
# Date created:                20th July 2004
# Whom:                        Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	trustedqsl
PORTVERSION=	1.11
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	trustedqsl
DISTFILES=	tqsllib-2.0.tar.gz TrustedQSL-1.11.tar.gz

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio Station electronic trusted logbook

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		wx_base-2.6:${PORTSDIR}/x11-toolkits/wxgtk26

USE_PERL5=	yes
USE_GETOPT_LONG=	yes
INSTALLS_SHLIB=	yes
MAKE_ENV=	INCDIR="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	can not build on 4.x
.endif

post-patch:
	@${CP} ${FILESDIR}/Makefile  ${WRKSRC}
	@${REINPLACE_CMD} -e 's|%%INSTALL%%|${INSTALL_PROGRAM}|' \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.TrustedQSL-1.11  ${WRKSRC}/TrustedQSL-1.11/Makefile
	@${CP} ${FILESDIR}/sysconfig.h.TrustedQSL-1.11  ${WRKSRC}/TrustedQSL-1.11/sysconfig.h

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@for f in ${EXTRACT_ONLY}; do  \
		if ! (cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$f ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi \
	done

post-install:
	${MKDIR} ${PREFIX}/etc/tqsl
	${INSTALL_DATA} ${WRKSRC}/tqsllib-2.0/config.xml ${PREFIX}/etc/tqsl/config.xml
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tqslcert
	@${MKDIR} ${PREFIX}/share/doc/tqslapp
	@${INSTALL_DATA} ${WRKSRC}/TrustedQSL-1.11/help/tqslcert/* ${PREFIX}/share/doc/tqslcert/
	@${INSTALL_DATA} ${WRKSRC}/TrustedQSL-1.11/help/tqslapp/* ${PREFIX}/share/doc/tqslapp/
	@${INSTALL_DATA} ${WRKSRC}/tqsllib-2.0/LICENSE ${PREFIX}/share/doc/tqsllib
	@${INSTALL_DATA} ${WRKSRC}/tqsllib-2.0/ChangeLog ${PREFIX}/share/doc/tqsllib
.endif
	@${ECHO}
	@${ECHO} trustedqsl is now installed.
	@${ECHO} You will have to create a directory .tqsl in your
	@${ECHO} home directory and setup a copy of
	@${ECHO} ${PREFIX}/etc/tqsl/config.xml here
	@${ECHO} before this program will run correctly.
	@${ECHO}

.include <bsd.port.post.mk>
