# New ports collection makefile for:	jless
# Date created:		7 March 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	less
PORTVERSION=	332
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.big.or.jp/pub/usr2/jam/less/contrib/
MASTER_SITE_SUBDIR=	less
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		regex_cs-lwp9k.shar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.big.or.jp/pub/usr2/jam/less/
PATCHFILES=	${DISTNAME}-iso242.patch.gz \
		${DISTNAME}-iso242-243.patch.gz \
		${DISTNAME}-iso243-244.patch.gz \
		${DISTNAME}-iso244-245.patch.gz \
		${DISTNAME}-iso245-247.patch.gz \
		${DISTNAME}-iso247-248.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	nobu@psrc.isac.co.jp

GNU_CONFIGURE=	yes
CONFIGURE_ARGS = --with-cs-regex
MAN1=		jless.1 jlesskey.1

post-patch:
		(cd ${WRKSRC} ; \
			zcat ${DISTDIR}/regex_cs-lwp9k.shar.gz | ${SH} )

.include <bsd.port.mk>
