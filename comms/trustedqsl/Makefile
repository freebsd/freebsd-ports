# New ports collection makefile for:   TrustedQSL
# Date created:                20th July 2004
# Whom:                        Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	trustedqsl
PORTVERSION=	1.10
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	trustedqsl
DISTFILES=	tqsllib-1.4.tar.gz TrustedQSL-1.10.tar.gz

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio Station electronic trusted logbook

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2 \
		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
MAKE_ENV=	INCDIR="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${CP} ${FILESDIR}/Makefile  ${WRKSRC}
	${CP} ${FILESDIR}/Makefile.tqsllib  ${WRKSRC}/tqsllib/Makefile
	${CP} ${FILESDIR}/Makefile.tqsllib-apps  ${WRKSRC}/tqsllib-apps/Makefile

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@for file in ${EXTRACT_ONLY}; do  \
		if ! (cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi \
	done

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tqslcert
	@${MKDIR} ${PREFIX}/share/doc/tqslapp
	@${CP} ${WRKSRC}/tqsllib-apps/tqslcert_help/* ${PREFIX}/share/doc/tqslcert/
	@${CP} ${WRKSRC}/tqsllib-apps/tqsl_help/* ${PREFIX}/share/doc/tqslapp/
.endif

.include <bsd.port.mk>
