# Created by: torstenb
# $FreeBSD$

PORTNAME=	mirror
PORTVERSION=	2.9
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	ftp://sunsite.ualberta.ca/pub/Mirror/mirror/ \
		http://komquats.com/distfiles/ \
		LOCAL/cy

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	ftp.pl_wupatch

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Mirror packages on remote sites

BROKEN=		unfetchable

MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USES=		perl5 shebangfix
SHEBANG_FILES=	dateconv.pl ftp.pl  lchat.pl mirror.pl pkgs_to_mmin.pl \
		do_unlinks.pl install.pl lsparse.pl mm.pl  prune_logs.pl

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mirror

.include <bsd.port.mk>
