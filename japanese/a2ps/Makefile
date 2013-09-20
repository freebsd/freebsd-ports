# Created by: SAITO Itsuro <saito@miv.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	a2ps
PORTVERSION=	1.45
PORTREVISION=	3
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/lang/perl/sra-scripts/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|tota/a2ps|}
DISTNAME=	${PORTNAME}.pl-${PORTVERSION}
EXTRACT_SUFX=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Text file to postscript converter (with Japanese support)

LICENSE=	BSD

RUN_DEPENDS=	paperconf:${PORTSDIR}/print/libpaper

PLIST_FILES=	bin/a2ps-j
EXTRACT_CMD=	${INSTALL_SCRIPT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	a2ps-j
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} \
		-e 's,%%PERL%%,${PERL},' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${WRKDIR}/a2ps-j

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/a2ps-j ${PREFIX}/bin

.include <bsd.port.mk>
