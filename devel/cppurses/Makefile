# $FreeBSD$

PORTNAME=	cppurses
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-4
DISTVERSIONSUFFIX=	-g791dfe5
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal User Interface framework with NCurses

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++14-lang ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	a-n-t-h-o-n-y
GH_PROJECT=	CPPurses
GH_TUPLE=	\
		a-n-t-h-o-n-y:Signals:86d312f:signals/libs/Signals \
		a-n-t-h-o-n-y:Chess-curses:f597add:demos_chess/demos/chess \
		a-n-t-h-o-n-y:Optional:a141da0:signals_optional/libs/Signals/libs/Optional
USE_LDCONFIG=	yes

.include <bsd.port.mk>
