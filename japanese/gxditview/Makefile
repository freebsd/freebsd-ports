# New ports collection makefile for:	gxditview (part of ja-groff)
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	gxditview
PORTVERSION=	0.99.1.1
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff
DISTNAME=	groff-1.11.1

PATCH_SITES=	${MASTER_SITE_PORTS_JP} \
		http://www.tg.rim.or.jp/~inagaki/
PATCHFILES=	jgroff-${PORTVERSION:R}.diff.gz \
		jgroff-${PORTVERSION:R}-${PORTVERSION}.diff.gz
PATCH_DIST_ARGS=	-d ${WRKSRC}/.. --forward --quiet -E -p1

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	groff:${PORTSDIR}/japanese/groff

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/xditview
MAN1=		gxditview.1

post-patch:
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Imakefile

.include <bsd.port.mk>
