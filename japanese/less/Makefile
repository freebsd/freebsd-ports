# New ports collection makefile for:	jless
# Date created:		7 March 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	less+iso
PORTVERSION=	358.254
CATEGORIES=	japanese
MASTER_SITES=	http://www.io.com/~kazushi/less/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	less
DISTNAME=	less-${PORTVERSION:R}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		regex_cs-lwp9k.shar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	http://www.io.com/~kazushi/less/
PATCHFILES=	${DISTNAME}-iso${PORTVERSION:E}.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	k5@cheerful.com

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cs-regex
MAN1=		jless.1 jlesskey.1

DOCDIR=		${PREFIX}/share/doc/less
READMES=	README.iso README.regex README.iso.jp README.regex.jp

post-patch:
		(cd ${WRKSRC} ; \
	 ${RM} -f configure COPYING; \
	 ${GZCAT} ${DISTDIR}/regex_cs-lwp9k.shar.gz | ${SH} )

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${READMES} ${DOCDIR})
.endif

.include <bsd.port.mk>
