# New ports collection makefile for:	mpg123
# Version required:		0.59r
# Date created:			25 June 1997
# Whom:				Carey Jones <mcj@acquiesce.org>
#
# $FreeBSD$
#

DISTNAME=	mpg123-0.59r
CATEGORIES=	audio
MASTER_SITES=	http://www.mpg123.de/mpg123/ \
		http://www-ti.informatik.uni-tuebingen.de/~hippm/mpg123/ \
		ftp://ftp.tu-clausthal.de/pub/unix/audio/mpg123/ \
		http://ftp.tu-clausthal.de/pub/unix/audio/mpg123/

MAINTAINER=	jkoshy@freebsd.org

MAN1=		mpg123.1

.include <bsd.port.pre.mk>

ALL_TARGET=	freebsd

pre-configure:
.if $(MACHINE_ARCH) == "i386"
.if !defined(OPT_ARCH) || (($(OPT_ARCH) != "i486") && ($(OPT_ARCH) != "i586"))
	@echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@echo "Please considering setting OPT_ARCH to match your hardware to build mpg123"
	@echo "optimised for your hardware (e.g: make OPT_ARCH=i486)"
.if $(PORTOBJFORMAT) == "elf"
	@echo "Valid values are: i486, i586"
.else
	@echo "Valid values are: i486"
.endif
	@echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
.endif
.endif

.include <bsd.port.post.mk>
