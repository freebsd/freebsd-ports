# New ports collection makefile for:	xanim
# Version required:     2.70.4.3
# Date created:         Sat Nov 5 11:43:03 PST 1994
# Whom:                 piero
#
# $Id: Makefile,v 1.7 1996/03/09 11:43:35 asami Exp $
#

DISTNAME=       xanim27043
PKGNAME=        xanim-2.70.4.3
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://ftp.portal.com/pub/podlipec/ \
		ftp://ftp.portal.com/pub/podlipec/cinepak/ \
		ftp://ftp.portal.com/pub/podlipec/indeo/
EXTRACT_ONLY=   ${DISTNAME}.tar.gz
EXTRA_FILES=	xa2.0_cvid_netbsd386.o.Z xa2.0_iv32_netbsd386.o.Z
DISTFILES=	${EXTRACT_ONLY} ${EXTRA_FILES}

USE_IMAKE=	yes

post-extract:
	@for file in ${EXTRA_FILES}; do \
	  cp ${DISTDIR}/$$file ${WRKSRC}; \
	  uncompress ${WRKSRC}/$$file; \
	done

.include <bsd.port.mk>

