# New ports collection makefile for:	jless
# Date created:		7 March 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	less+iso
PORTVERSION=	382.258
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://www25.big.jp/~jam/less/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sf
DISTNAME=	less-${PORTVERSION:R}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		regex_cs-lwp9k.shar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	http://www25.big.jp/~jam/less/
PATCHFILES=	${DISTNAME}-iso${PORTVERSION:E}.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Less + zcat + ISO-2022 - a pager similar to more and pg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cs-regex
MAN1=		jless.1 jlesskey.1

DOCDIR=		${PREFIX}/share/doc/less
READMES=	README.iso README.regex README.iso.jp README.regex.jp

post-patch:
	(cd ${WRKSRC} ; \
	 ${RM} -f COPYING; \
	 ${GZCAT} ${DISTDIR}/regex_cs-lwp9k.shar.gz | ${SH} )

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${READMES} ${DOCDIR})
.endif

.include <bsd.port.mk>
