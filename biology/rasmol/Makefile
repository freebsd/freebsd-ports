# New ports collection Makefile for: rasmol
# Version required:     2.7.1
# Date created:         Dec 4 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

DISTNAME=       RasMol_2.7.1
PKGNAME=        rasmol-2.7.1
CATEGORIES=     biology
MASTER_SITES=   ftp://ftp.bernstein-plus-sons.com/software/

MAINTAINER=     frankch@waru.life.nthu.edu.tw

WRKSRC=		$(WRKDIR)/RasMol_2.7.1/src/
USE_IMAKE=	yes

MAN1=		rasmol.1

pre-extract:
	@${ECHO} ""
	@${ECHO} You can set the color depth to match your X server in
	@${ECHO} ${WRKSRC}Imakefile
	@${ECHO} before building.
	@${ECHO} ""

.include <bsd.port.mk>
