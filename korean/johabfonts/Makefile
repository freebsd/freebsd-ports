# New ports collection makefile for:	johabfonts
# Date created:		15 Mar 1998
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	johabfonts
PORTVERSION=	3.04
CATEGORIES=	korean x11-fonts
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/terminal/hanterm/hanterm304beta/fonts/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/terminal/hanterm/hanterm304beta/fonts/
DISTNAME=	hanterm304fonts

MAINTAINER=	cjh@FreeBSD.org

USE_IMAKE=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

NO_INSTALL_MANPAGES= yes

pre-install:
	-${MKDIR} ${PREFIX}/lib/X11/fonts/local

.include <bsd.port.post.mk>
