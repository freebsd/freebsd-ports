# New ports collection makefile for:    elk
# Version required:     3.0pl3
# Date created:         08 March 1995
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	elk-3.0
PKGNAME=	elk-3.0.3
CATEGORIES=	lang
MASTER_SITES=	http://www-rn.informatik.uni-bremen.de/software/elk/dist/

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
PATCH_STRIP=	-p1
ALL_TARGET=	default
MAN1=		elk.1

#
# we install the scheme binary as ${PREFIX}/bin/elk
# to avoid a clash with mit-scheme.
#

pre-install:
	@${MKDIR} ${PREFIX}/share/elk

post-install:
	@(cd ${PREFIX}/share/elk; \
	  ${CP} bin/scheme ${PREFIX}/bin/elk; \
	  ${MKDIR} ${PREFIX}/include/elk; \
	  ${CP} -R include/* ${PREFIX}/include/elk; \
	  ${RM} -rf bin include)
	@${INSTALL_MAN} ${WRKSRC}/doc/man/elk.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
