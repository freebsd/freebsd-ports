# New ports collection makefile for:	tooLAME
# Date created:		Wed May 22 16:53:26 BRT 2002
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	toolame
PORTVERSION=	0.2l
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Optimized mpeg 1/2 layer 2 audio encoder

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
ALL_TARGET=	${PORTNAME}

DOC_FILES=	FUTURE HISTORY LGPL.txt README

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
	@${REINPLACE_CMD} -E -e 's|\$$\(TWEAKS\)||' \
		${WRKSRC}/Makefile
.endif
.ifndef(WITH_PROFILED)
	@${REINPLACE_CMD} -E -e 's|\$$\(PG\)||' \
		${WRKSRC}/Makefile
.endif
	@${REINPLACE_CMD} -E -e \
		's@\$$\((ARCH|OPTIM|WARNINGS)\)@@g' \
		${WRKSRC}/Makefile

post-configure:
# C{C,FLAGS} safeness
	@${REINPLACE_CMD} -E -e \
		's|^(CC[[:space:]]*=).+$$|\1${CC} ${CFLAGS}|' \
		${WRKSRC}/Makefile

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/toolame ${PREFIX}/bin

.include <bsd.port.post.mk>
