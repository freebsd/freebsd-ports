# New ports collection makefile for:	rpm
# Date created:		30 April 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rpm
PORTVERSION=	3.0.6
PORTREVISION=	5
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-3.0.x/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.rpm.org/pub/rpm/dist/rpm-3.0.x/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	bz2.1:${PORTSDIR}/archivers/bzip2 \
		intl.1:${PORTSDIR}/devel/gettext \
		popt.0:${PORTSDIR}/devel/popt

USE_GMAKE=	yes
USE_AUTOMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-glob
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=		gendiff.1
MAN8=		rpm.8 rpm2cpio.8

post-patch:
.for file in rpm.c doc/rpm.8 lib/macro.c lib/rpmrc.c
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

post-install:
		${INSTALL_MAN} ${WRKSRC}/doc/gendiff.1 ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/doc/rpm.8 ${PREFIX}/man/man8
		${INSTALL_MAN} ${WRKSRC}/doc/rpm2cpio.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
