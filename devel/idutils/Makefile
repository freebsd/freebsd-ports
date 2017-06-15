# Created by: pst@FreeBSD.org
# $FreeBSD$

PORTNAME=	idutils
PORTVERSION=	4.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	peterjeremy@acm.org
COMMENT=	The classic Berkeley gid/lid tools for looking up variables in code

CONFLICTS=	coreutils-[0-9]* linux-gid-[0-9]* sh-utils-[0-9]*

LICENSE=	GPLv3

OPTIONS_DEFINE=	NLS

USES=		charsetfix tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	EMACS='no'
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		idutils

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

OPTIONS_SUB=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/lisp/idutils.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp

.include <bsd.port.mk>
