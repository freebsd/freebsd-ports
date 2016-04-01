# Created by: Giacomo Mariani <giacomomariani_at_yahoo_dot_it>
# $FreeBSD$

PORTNAME=	clewn
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	devel editors
MASTER_SITES=	SF/${PORTNAME}/OldFiles/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	giacomomariani@yahoo.it
COMMENT=	Clewn provides Gdb support within Vim

RUN_DEPENDS=	vim:editors/vim

USES=		gmake ncurses readline
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	vimdir=${PREFIX}/share/vim/vimfiles

post-patch:
	${REINPLACE_CMD} -e 's|-lcurses|-lncurses|' ${WRKSRC}/configure

.include <bsd.port.mk>
