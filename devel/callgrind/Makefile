# New ports collection makefile for:	calltree
# Date created:				Jun 3 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	callgrind
PORTVERSION=	0.9.8
CATEGORIES=	devel
MASTER_SITES=	http://kcachegrind.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Valgrind skin for cache simulation and call tracing

# see http://lists.freebsd.org/pipermail/cvs-ports/2006-December/112797.html
#IGNORE=	Dumps core \(SIGBUS\). \(Also v. 0.9.10\!\)

ONLY_FOR_ARCHS=	i386
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

OPTIONS=	VALGRIND_SNAPSHOT	"Depend on snapshot version of valgrind" off
.include <bsd.port.pre.mk>

.if defined (WITH_VALGRIND_SNAPSHOT)
RUN_DEPENDS=	valgrind:${PORTSDIR}/devel/valgrind-snapshot
BUILD_DEPENDS=	valgrind:${PORTSDIR}/devel/valgrind-snapshot
.else
RUN_DEPENDS=	valgrind:${PORTSDIR}/devel/valgrind
BUILD_DEPENDS=	valgrind:${PORTSDIR}/devel/valgrind
.endif

pre-patch:
.ifdef(NOPORTDOCS)
	${FIND} ${WRKSRC} -name "Makefile.in" -exec \
	${REINPLACE_CMD} -e "s/docs//g" {} \;
.endif

.include <bsd.port.post.mk>
