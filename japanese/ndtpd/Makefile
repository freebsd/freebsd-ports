# New ports collection makefile for:	ndtpd
# Version required:		2.2
# Date created:			4 Aug 1998
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $Id: Makefile,v 1.5 1998/10/16 04:32:50 jseger Exp $
#

DISTNAME=	ndtpd-2.2
PKGNAME=	ja-ndtpd-2.2
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/ \
		ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/old/

MAINTAINER=	m-kasahr@sra.co.jp

LIB_DEPENDS=	eb.2:${PORTSDIR}/japanese/eb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --with-eb --with-zlib \
		--with-eb-includes=${PREFIX}/include \
		--with-eb-libraries=${PREFIX}/lib

CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"
.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	Maybe_interactive_at_install_stage
.endif

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in ndtpd ndtpd-ja
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor
	@${SETENV} PKG_PREFIX=${PREFIX} IS_INTERACTIVE="${IS_INTERACTIVE}" \
	    ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
