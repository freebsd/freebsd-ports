# New ports collection makefile for:	johabfonts
# Version required:     3.04
# Date created:		15 Mar 1998
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id$
#

DISTNAME=       hanterm304fonts
PKGNAME=	ko-johabfonts-3.04
CATEGORIES=	korean x11
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/terminal/hanterm/hanterm304beta/fonts/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/terminal/hanterm/hanterm304beta/fonts/

MAINTAINER=	junker@jazz.snu.ac.kr

USE_IMAKE=	yes
NO_INSTALL_MANPAGES= yes

# to show a warning message to add fontpath for these fonts
post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
