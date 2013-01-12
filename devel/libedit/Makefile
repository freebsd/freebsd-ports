# Created by: jasone
# $FreeBSD$

PORTNAME=	libedit
PORTVERSION=	2.6.10
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.astron.com/pub/libedit/ \
		http://www.canonware.com/download/libedit/

MAINTAINER=	rodrigo@bebik.net
COMMENT=	Command line editing library

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=		editline.3
MAN5=		editrc.5
MLINKS=		editline.3 el_init.3 \
		editline.3 el_end.3 \
		editline.3 el_reset.3 \
		editline.3 el_gets.3 \
		editline.3 el_getc.3 \
		editline.3 el_push.3 \
		editline.3 el_parse.3 \
		editline.3 el_set.3 \
		editline.3 el_get.3 \
		editline.3 el_source.3 \
		editline.3 el_resize.3 \
		editline.3 el_line.3 \
		editline.3 el_insertstr.3 \
		editline.3 el_deletestr.3 \
		editline.3 history_init.3 \
		editline.3 history_end.3 \
		editline.3 history.3
MANCOMPRESSED=	no

post-extract:
	${MV} ${WRKSRC}/readline ${WRKSRC}/editline

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS -O|CFLAGS|g ; \
		 s|MAJOR="2"|MAJOR="6"|g' ${WRKSRC}/configure

.include <bsd.port.mk>
