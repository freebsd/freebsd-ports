# Created by: pst@FreeBSD.org
# $FreeBSD$

PORTNAME=	idutils
PORTVERSION=	4.6
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	peterjeremy@acm.org
COMMENT=	The classic Berkeley gid/lid tools for looking up variables in code

CONFLICTS=	coreutils-[0-9]* linux-gid-[0-9]* sh-utils-[0-9]*

USES+=		charsetfix
LICENSE=	GPLv3
USE_XZ=		yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		idutils
MAN1=		aid.1 defid.1 eid.1 fid.1 fnid.1 gid.1 lid.1 mkid.1 xtokid.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

# Port configure script will auto-install the .elc file if [x]emacs is found
.if exists(${LOCALBASE}/bin/emacs) || exists(${LOCALBASE}/bin/xemacs)
PLIST_SUB+=	ELC=""
.else
PLIST_SUB+=	ELC="@comment "
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/lisp/idutils.el ${PREFIX}/share/emacs/site-lisp

.include <bsd.port.mk>
