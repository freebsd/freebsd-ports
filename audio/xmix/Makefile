# New ports collection makefile for:	xmix
# Version required:	2.1
# Date created:		30 June 1995
# Whom:			janek@gaja.ipan.lublin.pl
#

DISTNAME=	xmix-2.1
CATEGORIES+=	audio
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/apps/sound/mixers/ \
		ftp://ftp.icm.edu.pl/pub2/linux/apps/sound/mixers/

PATCH_SITES=	ftp://sunsite.unc.edu/pub/Linux/apps/sound/mixers/ \
		ftp://ftp.icm.edu.pl/pub2/linux/apps/sound/mixers/
PATCHFILES=	xmix-2.1.mixers.patch

USE_IMAKE=	yes
WRKSRC=		$(WRKDIR)/xmix

pre-install:
	cp ${WRKSRC}/xmix.1 ${WRKSRC}/xmix.man
	/usr/bin/install -c -m 0444 $(WRKSRC)/XMix /usr/X11R6/lib/X11/app-defaults

.include <bsd.port.mk>
