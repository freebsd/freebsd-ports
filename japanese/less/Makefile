# New ports collection makefile for:	jless
# Version required:	332
# Date created:		7 March 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.14 1998/10/10 04:01:45 steve Exp $
#

DISTNAME=	less-332
PKGNAME=	ja-less-332
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.big.or.jp/pub/usr2/jam/less/contrib/
MASTER_SITE_SUBDIR=	less
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		regex_cs-lwp9k.shar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.big.or.jp/pub/usr2/jam/less/
PATCHFILES=	less-332-iso242.patch.gz \
		less-332-iso242-243.patch.gz \
		less-332-iso243-244.patch.gz \
		less-332-iso244-245.patch.gz \
		less-332-iso245-247.patch.gz \
		less-332-iso247-248.patch.gz

PATCH_DIST_STRIP=	-p1

MAINTAINER=	nobu@psrc.isac.co.jp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS = --with-cs-regex
MAN1=		jless.1 jlesskey.1

post-patch:
		(cd ${WRKSRC} ; \
			zcat ${DISTDIR}/regex_cs-lwp9k.shar.gz | ${SH} )

.include <bsd.port.mk>
