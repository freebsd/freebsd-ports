# Created by: Eric L. Hernes <erich@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ical
PORTVERSION=	2.2
PORTREVISION=	4
CATEGORIES=	deskutils tk
MASTER_SITES=	ftp://ftp.sunet.se/pub/vendor/sco/skunkware/src/shellutil/

PATCH_SITES=	http://www.isi.edu/~johnh/SOFTWARE/ICAL/
PATCHFILES=	ical-2.3.1-upvar.patch

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Calendar application

LICENSE=	GPLv2

USE_TK=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tclconfig=${TCL_LIBDIR} \
		--with-tclhdir=${TCL_INCLUDEDIR} \
		--with-tclsh=${TCLSH} \
		--with-tkconfig=${TK_LIBDIR} \
		--with-tkhdir=${TK_INCLUDEDIR}

MAN1=		ical.1

post-patch:
	@${REINPLACE_CMD} -e 's,tcl->result,Tcl_GetStringResult(tcl),' \
		${WRKSRC}/ical.C

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
