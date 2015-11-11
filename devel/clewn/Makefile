# Created by: Giacomo Mariani <giacomomariani_at_yahoo_dot_it>
# $FreeBSD$

PORTNAME=	clewn
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	devel editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	giacomomariani@yahoo.it
COMMENT=	Clewn provides Gdb support within Vim

BROKEN=		Does not fetch
RUN_DEPENDS=	vim:${PORTSDIR}/editors/vim

USES=		gmake readline
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	vimdir=${PREFIX}/share/vim/vimfiles

.include <bsd.port.mk>
