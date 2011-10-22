# Ports collection makefile for:  epm
# Date created:			  20 Nov 2004
# Whom:				  NAKATA Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	epm
PORTVERSION=	4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_EASYSW}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	-source.tar.bz2

MAINTAINER=	office@FreeBSD.org
COMMENT=	A free UNIX software/file packaging program

LICENSE=	GPLv2

MAKE_JOBS_UNSAFE=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf

MAN1=		epm.1 epminstall.1 mkepmlist.1 setup.1
MAN5=		epm.list.5 setup.types.5

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/docdir/d' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
