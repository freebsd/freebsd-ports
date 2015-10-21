# Created by: Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
# $FreeBSD$

PORTNAME=	man
PORTVERSION=	1.1j
PORTREVISION=	9
CATEGORIES=	japanese
MASTER_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/ \
		PORTS_JP
DISTNAME=	jp-${PORTNAME}-${PORTVERSION}

PATCH_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/
PATCHFILES=	jp-man-1.1j-ex-20020115.patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manual display command for Japanese (EUC)

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/groff:${PORTSDIR}/japanese/groff \
		jless:${PORTSDIR}/japanese/less

MAKE_ENV=	GZCAT=${GZCAT} GZIP_CMD="${GZIP_CMD}"
USES=		shebangfix
SHEBANG_FILES=	catman/catman.perl makewhatis/makewhatis.perl

post-patch:
.for file in	apropos/apropos.sh catman/catman.perl \
		makewhatis/jmakewhatis.local.man \
		makewhatis/jmakewhatis.local.man.eng \
		makewhatis/makewhatis.local.sh \
		man/locale.c manpath/manpath.config
	${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
