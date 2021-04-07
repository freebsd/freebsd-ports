PORTNAME=	cppurses
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3-5
DISTVERSIONSUFFIX=	-g342a389
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
		a-n-t-h-o-n-y:Signals:fb1137a66aac53c9a82356feb9159fd911d4f213:a_n_t_h_o_n_y_Signals/libs/Signals \
		a-n-t-h-o-n-y:Chess-curses:f597add641463b5aeb7382d4f804f5c4e6df69d5:a_n_t_h_o_n_y_Chess_curses/demos/chess \
		a-n-t-h-o-n-y:Optional:daa1e69b7ff27aa05e47081ac90794f7881eaf5d:a_n_t_h_o_n_y_Optional/libs/Signals/libs/Optional
USE_LDCONFIG=	yes

.include <bsd.port.mk>
