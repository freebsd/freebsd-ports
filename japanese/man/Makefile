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

RUN_DEPENDS=	${LOCALBASE}/bin/groff:japanese/groff \
		jless:japanese/less

BROKEN_mips=	fails to compile: man.c:37:10: fatal error: 'config.h' file not found

MAKE_ENV=	GZCAT=${GZCAT} GZIP_CMD="${GZIP_CMD}"
USES=		shebangfix
SHEBANG_FILES=	catman/catman.perl makewhatis/makewhatis.perl

# Fix build with clang11
CFLAGS+=	-fcommon
# XXX PIE static libraries currently not supported by base system /usr/share/mk
MAKE_ARGS+=	WITHOUT_PIE=true

post-patch:
.for file in	apropos/apropos.sh catman/catman.perl \
		makewhatis/jmakewhatis.local.man \
		makewhatis/jmakewhatis.local.man.eng \
		makewhatis/makewhatis.local.sh \
		man/locale.c manpath/manpath.config
	${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|g" ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
