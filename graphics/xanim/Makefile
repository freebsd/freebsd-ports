# New ports collection makefile for:	xanim
# Version required:     2.70.3
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 piero
#
# $Id: Makefile,v 1.5 1995/09/22 19:05:21 ache Exp $
#

DISTNAME=       xanim2703
PKGNAME=        xanim-2.70.3
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://ftp.portal.com/pub/podlipec/
MASTER_SITES+=	ftp://ftp.portal.com/pub/podlipec/cinepak/
MASTER_SITES+=	ftp://ftp.portal.com/pub/podlipec/indeo/
EXTRACT_ONLY=	xanim2703.tar.gz
DISTFILES=	${EXTRACT_ONLY} xa2.0_cvid_netbsd386.o.Z
DISTFILES+=	xa2.0_iv32_netbsd386.o.Z
USE_IMAKE=	is_set

post-extract:
	@cp ${DISTDIR}/xa2.0_cvid_netbsd386.o.Z ${WRKSRC}
	@uncompress ${WRKSRC}/xa2.0_cvid_netbsd386.o.Z
	@cp ${DISTDIR}/xa2.0_iv32_netbsd386.o.Z ${WRKSRC}
	@uncompress ${WRKSRC}/xa2.0_iv32_netbsd386.o.Z

.include <bsd.port.mk>

