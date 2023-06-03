PORTNAME=	dmucs
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Distributed Multi-User Compilation System (for use with distcc)
WWW=		http://dmucs.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to compile: passing char * to parameter of incompatible type __builtin_va_list
BROKEN_armv6=		fails to compile: passing char * to parameter of incompatible type __builtin_va_list
BROKEN_armv7=		fails to compile: passing char * to parameter of incompatible type __builtin_va_list

USES=	tar:bzip2

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/dmucs bin/gethost bin/loadavg bin/monitor bin/remhost

.include <bsd.port.pre.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
	@${REINPLACE_CMD} -e 's|CFLAGS    = -O -I./HDR|CFLAGS=-Wno-error=int-conversion -O -I./HDR|' \
		${WRKSRC}/COSMIC/Makefile
.endif

.include <bsd.port.post.mk>
