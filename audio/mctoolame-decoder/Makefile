# New ports collection makefile for:	mctooLAME decoder
# Date created:		Thu Mar 27 20:32:42 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mctoolame
PORTVERSION=	0.1.a
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-decoder
DISTNAME=	${PORTNAME}d-${PORTVERSION:C/\.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A LayerII MPEG Audio decoder which supports multi-channel encoding

USE_GMAKE=	yes
ALL_TARGET=
PLIST_SUB=	PKGNAMESUFFIX="${PKGNAMESUFFIX}"

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} '>>>'
	@${ECHO_MSG} '>>> You can enable extra optimizations by defining WITH_OPTIMIZED_CFLAGS'
	@${ECHO_MSG} ">>> For example, 'make WITH_OPTIMIZED_CFLAGS=yes'"
.endif
	@${ECHO_MSG} '>>>'
.ifndef(WITH_PROFILED)
	@${ECHO_MSG} ">>> You can enable profiling by defining WITH_PROFILED"
.endif

.include <bsd.port.pre.mk>

post-patch:
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -E \
		-e 's|\$$\(TWEAKS\)||' \
		${WRKSRC}/Makefile
.endif
.ifndef(WITH_PROFILED)
	@${REINPLACE_CMD} -E \
		-e 's|\$$\(PG\)||' \
		${WRKSRC}/Makefile
.endif
	@${REINPLACE_CMD} -E \
		-e 's@\$$\((ARCH|OPTIM|WARNINGS)\)@@g' \
		${WRKSRC}/Makefile

post-configure:
# C{C,FLAGS} safeness
	@${REINPLACE_CMD} -E \
		-e 's|^(CC[[:space:]]*=).+$$|\1${CC} ${CFLAGS}|' \
		${WRKSRC}/Makefile

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}${PKGNAMESUFFIX}/html
	@${INSTALL_DATA} ${WRKSRC}/html/* ${DOCSDIR}${PKGNAMESUFFIX}/html
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/mctoolamed ${PREFIX}/bin

.include <bsd.port.post.mk>
