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
DISTNAME=       hanterm304fonts

USE_IMAKE=	yes
NO_INSTALL_MANPAGES= yes

pre-install:
	-${MKDIR} ${PREFIX}/lib/X11/fonts/local

.include <bsd.port.mk>
