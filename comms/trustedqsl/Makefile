# New ports collection makefile for:   TrustedQSL
# Date created:                20th July 2004
# Whom:                        Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	trustedqsl
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	trustedqsl
DISTFILES=	tqsllib-1.4.tar.gz TrustedQSL-1.11.tar.gz

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio Station electronic trusted logbook

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		wx_base-2.6:${PORTSDIR}/x11-toolkits/wxgtk26

USE_PERL5=	yes
USE_GETOPT_LONG=	yes
MAKE_ENV=	INCDIR="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"does not compile"
.endif

post-patch:
	${CP} ${FILESDIR}/Makefile  ${WRKSRC}
	${CP} ${FILESDIR}/Makefile.tqsllib  ${WRKSRC}/tqsllib/Makefile
	${CP} ${FILESDIR}/Makefile.TrustedQSL-1.11  ${WRKSRC}/TrustedQSL-1.11/Makefile
	${CP} ${FILESDIR}/sysconfig.h.tqsllib  ${WRKSRC}/tqsllib/sysconfig.h
	${CP} ${FILESDIR}/sysconfig.h.TrustedQSL-1.11  ${WRKSRC}/TrustedQSL-1.11/sysconfig.h

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tqslcert
	@${MKDIR} ${PREFIX}/share/doc/tqslapp
	@${CP} ${WRKSRC}/TrustedQSL-1.11/help/tqslcert/* ${PREFIX}/share/doc/tqslcert/
	@${CP} ${WRKSRC}/TrustedQSL-1.11/help/tqslapp/* ${PREFIX}/share/doc/tqslapp/
.endif

.include <bsd.port.post.mk>
