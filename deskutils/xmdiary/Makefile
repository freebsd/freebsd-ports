# New ports collection makefile for:	xmdiary
# Version required:	3.0.1
# Date created:		29 Sep 1997
# Whom:			mi@aldan.ziplink.net
#
# $Id: Makefile,v 1.1.1.1 1998/03/09 13:04:57 tg Exp $
#

DISTNAME=	xmdiary-3.0.1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	office
DISTFILES=      ${DISTNAME}.tar.gz xmdfix.gz

MAINTAINER=	mi@aldan.ziplink.net

NO_CDROM=	"Don't sell for profit"
EXTRACT_ONLY=	${DISTNAME}.tar.gz
REQUIRES_MOTIF=	yes
USE_IMAKE=	yes

pre-patch:
	for node in `tar tzf ${DISTDIR}/xmdfix.gz` ; \
	do \
		test -f $(WRKSRC)/$$node && ${RM} -f $(WRKSRC)/$$node ; \
	done
	cd  $(WRKSRC) && tar xzpf ${DISTDIR}/xmdfix.gz

post-patch:
	@echo removing the "malloc.h" includes
	${SCRIPTDIR}/nomalloc $(WRKSRC) 2>&1 > /dev/zero
	@echo removing unneccessary DependTarget from Imakefile-s
	${SCRIPTDIR}/noextradepend $(WRKSRC) 2>&1 > /dev/zero

.include <bsd.port.mk>
