# New ports collection makefile for:	PCB
# Version required:	1.2 patchlevel 3
# Date created:		19 October 1994
# Whom:			mr
#
# $Id: Makefile,v 1.9 1995/04/11 20:13:02 asami Exp $
#

DISTNAME=	pcb-1.2.patch_03
PKGNAME=	pcb-1.2.3
CATEGORIES+=	cad
MASTER_SITES=	ftp://pluto.medizin.uni-ulm.de/pub/pcb-1.2/
EXTRACT_SUFX=	.tar.gz

EXEC_DEPENDS=	gm4:${PORTSDIR}/devel/m4

MAKE_FLAGS=	-f
MAKEFILE=	makefile
USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.mk>
