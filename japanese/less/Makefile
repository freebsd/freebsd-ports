# New ports collection makefile for:	jless
# Date created:		7 March 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	less+iso
PORTVERSION=	358.254
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://www.io.com/~kazushi/less/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sf
DISTNAME=	less-${PORTVERSION:R}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${XGTAGS}${EXTRACT_SUFX} \
		regex_cs-lwp9k.shar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		${XGTAGS}${EXTRACT_SUFX}

PATCH_SITES=	http://www.io.com/~kazushi/less/
PATCHFILES=	${DISTNAME}-iso${PORTVERSION:E}.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sf@FreeBSD.org

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cs-regex
MAN1=		jless.1 jlesskey.1

DOCDIR=		${PREFIX}/share/doc/less
READMES=	README.iso README.regex README.iso.jp README.regex.jp
XGTAGS=		${DISTNAME}-iso${PORTVERSION:E}+gtags-20010110

post-patch:
	(cd ${WRKSRC} ; \
	 ${RM} -f configure COPYING; \
	 ${GZCAT} ${DISTDIR}/regex_cs-lwp9k.shar.gz | ${SH} )
	${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/${XGTAGS}/${XGTAGS}.diff

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${READMES} ${DOCDIR})
	${INSTALL_DATA} ${WRKDIR}/${XGTAGS}/README ${DOCDIR}/README.gtags
.endif

.include <bsd.port.mk>
