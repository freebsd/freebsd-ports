# New ports collection makefile for:	gxditview (part of ja-groff)
# Version required:	1.10+0.99
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

DISTNAME=	groff-1.10
PKGNAME=	ja-gxditview-0.99
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	groff

PATCH_SITES=	ftp://ftp.ae.keio.ac.jp/pub/GNU/ \
		ftp://ftp.hipecs.hokudai.ac.jp/pub/GNU/jp/
PATCHFILES=	jgroff-0.99.diff.gz
PATCH_DIST_ARGS=?	-d ${WRKSRC}/.. --forward --quiet -E -p1

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	groff:${PORTSDIR}/japanese/groff

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/xditview
MAN1=		gxditview.1

post-patch:
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Imakefile

.include <bsd.port.mk>
