PORTNAME=	libpru
DISTVERSIONPREFIX=v
DISTVERSION=	0.5
CATEGORIES=	devel

MAINTAINER=	jmg@FreeBSD.org
# The maintainer says, if you're actively using this you are free to
# take this port.
COMMENT=	Library to interface with PRUs

LICENSE=	BSD2CLAUSE

IGNORE_DragonFly=	only supported on FreeBSD

USES=		cmake compiler

USE_GITHUB=	yes
GH_ACCOUNT=	rpaulo

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's/ -Weverything//'  ${WRKSRC}/CMakeLists.txt
.if ${CHOSEN_COMPILER_TYPE} == gcc
	${REINPLACE_CMD} -e 's/ -Werror//'  ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
