# Created by: Giacomo Mariani <giacomomariani_at_yahoo_dot_it>
# $FreeBSD$

PORTNAME=	clewn
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	devel editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	giacomomariani@yahoo.it
COMMENT=	Clewn provides Gdb support within Vim

RUN_DEPENDS=	vim>=6.3:${PORTSDIR}/editors/vim

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	vimdir=${PREFIX}/share/vim/vimfiles
USE_GMAKE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
