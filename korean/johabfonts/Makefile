# New ports collection makefile for:	hanterm304fonts
# Version required:     none
# Date created:		22 Mar 1997
# Whom:			Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.1.1.1 1997/04/18 08:45:51 asami Exp $
#

DISTNAME=       hanterm304fonts
PKGNAME=	ko-johabfonts-304
CATEGORIES=	korean x11
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/terminal/hanterm/ \
		ftp://sunsite.kren.nm.kr/pub/packages/hangul/terminal/hanterm/

MAINTAINER=	junker@jazz.snu.ac.kr

USE_IMAKE=	yes
NO_INSTALL_MANPAGES= yes

# to show a warning message to add fontpath for these fonts
post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
