# New ports collection makefile for:	gxditview (part of ja-groff)
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	gxditview
PORTVERSION=	0.100
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff
DISTNAME=	groff-1.15

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR= okazaki
PATCHFILES=	${DISTNAME}-jgroff-${PORTVERSION}-pl1.diff.gz
PATCH_DIST_ARGS=	-d ${WRKSRC}/.. --forward --quiet -E -p1

MAINTAINER=	okazaki@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/bin/groff:${PORTSDIR}/japanese/groff

USE_IMAKE=	yes
MAKE_ENV=	NIPPONDEFINES="-DNIPPON"
WRKSRC=		${WRKDIR}/${DISTNAME}/xditview
MAN1=		gxditview.1

post-patch:
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Imakefile

.include <bsd.port.mk>
