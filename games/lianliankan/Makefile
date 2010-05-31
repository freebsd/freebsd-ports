# New ports collection makefile for:	lianliankan
# Date created:				26 April 2006
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	lianliankan
DISTVERSION=	2.3beta1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/llk-linux/llk-linux-source/2.3beta1
DISTNAME=	llk_linux-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scarce recreation game

USE_AUTOTOOLS=	automake:19:env
USE_GNOME=	gtk20 esound
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-llk_linuxdocDATA
.endif

pre-configure:
.for f in install-sh depcomp missing COPYING INSTALL
	@${LN} -sf ${AUTOMAKE_DIR}/${f} ${WRKSRC}
.endfor

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/lianliankan.desktop ${PREFIX}/share/applications

.include <bsd.port.mk>
