# New ports collection makefile for:	jless
# Date created:		7 March 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	less+iso
PORTVERSION=	382.262
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork
DISTNAME=	less-${PORTVERSION:R}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		regex_cs-lwp9k.shar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	nork
PATCHFILES=	${DISTNAME}-iso258.patch.gz \
		${DISTNAME}-iso258-259.patch.gz \
		${DISTNAME}-iso259-260.patch.gz \
		${DISTNAME}-iso260-261.patch.gz \
		${DISTNAME}-iso261-${PORTVERSION:E}.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Less + zcat + ISO-2022 - a pager similar to more and pg

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cs-regex
MAN1=		jless.1 jlesskey.1

DOCSDIR=	${PREFIX}/share/doc/less
READMES=	README.iso README.regex README.iso.jp README.regex.jp

post-patch:
	(cd ${WRKSRC} ; \
	 ${RM} -f COPYING; \
	 ${GZCAT} ${DISTDIR}/regex_cs-lwp9k.shar.gz | ${SH}; \
	 ${PATCH} < ${PATCHDIR}/regex_cs.c.patch )
	${TOUCH} ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${READMES} ${DOCSDIR})
.endif

.include <bsd.port.mk>
