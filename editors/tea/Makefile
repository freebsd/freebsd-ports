# New ports collection makefile for:	TEA
# Date created:				13 Jul 2004
# Whom:					Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		tea
DISTVERSION=		9.1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_LOCAL} \
			http://tea.linux.kiev.ua/ \
			http://freebsd.nsu.ru/distfiles/
MASTER_SITE_SUBDIR=	danfe

MAINTAINER=		danfe@FreeBSD.org
COMMENT=		A simple and powerful GTK+ text editor

USE_X_PREFIX=		yes
USE_BZIP2=		yes
USE_REINPLACE=		yes
GNU_CONFIGURE=		yes
USE_GCC=		3.4
USE_GNOME=		gtk20
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=		ASPELL "Build with GNU aspell support" off

.include <bsd.port.pre.mk>

.if defined(WITH_ASPELL)
LIB_DEPENDS+=		aspell:${PORTSDIR}/textproc/aspell
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/tea/doc/|/doc/tea/|' \
		${WRKSRC}/src/tea_defs.h

.include <bsd.port.post.mk>
