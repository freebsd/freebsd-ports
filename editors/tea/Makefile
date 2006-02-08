# New ports collection makefile for:	TEA
# Date created:				13 Jul 2004
# Whom:					Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		tea
DISTVERSION=		12.0
CATEGORIES=		editors
MASTER_SITES=		http://tea.linux.kiev.ua/

MAINTAINER=		danfe@FreeBSD.org
COMMENT=		A simple and powerful GTK+ text editor

USE_X_PREFIX=		yes
USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USE_GCC=		3.3+
USE_GNOME=		gtk20
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=		TEA_ONLY "Build original GTK-only version" on \
			ASPELL "Build with GNU aspell support" on

.include <bsd.port.pre.mk>

.if !defined(WITH_TEA_ONLY)
CONFIGURE_ARGS+=	--enable-chai
USE_GNOME+=		gtksourceview
.endif

.if defined(WITH_ASPELL)
LIB_DEPENDS+=		aspell:${PORTSDIR}/textproc/aspell
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/tea/doc/|/doc/tea/|' \
		${WRKSRC}/src/tea_defs.h

.include <bsd.port.post.mk>
