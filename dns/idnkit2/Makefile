# Created by: Rafal Lesniak <fbsd@grid.einherjar.de>
# $FreeBSD$

PORTNAME=	idnkit
PORTVERSION=	2.2
CATEGORIES=	dns
MASTER_SITES=	http://jprs.co.jp/idn/

MAINTAINER=	fbsd@grid.einherjar.de
COMMENT=	Internationalized Domain Name toolkit 2

LICENSE_PERMS=	# permissive
LICENSE_NAME=	OSCL
LICENSE_FILE=	LICENSE.txt

LATEST_LINK=	${PORTNAME}${PORTVERSION:R}
CONFLICTS_INSTALL=	idnkit-1.*

USE_AUTOTOOLS=	libtool
USE_ICONV=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv=${LOCALBASE}

USE_LDCONFIG=	yes

MAN1=	idncheck.1 idncmp.1 idnconv2.1
MAN3=	idn_checkname.3 idn_comparenames.3 idn_comparenames2.3 \
	idn_decodename.3 idn_decodename2.3 idn_encodename.3 idn_nameinit.3 \
	idn_result_tostring.3 idn_setlanguage.3 idn_setlocalcheckfile.3 \
	idn_setlocalencoding.3 idn_version_getstring.3 idn_version_idnatable.3 \
	idn_version_libidn.3 idn_version_unicode.3 libidnkit.3 libidnkitlite.3
MAN5=	idn2.conf.5 idn2rc.5 idnalias.conf.5 idnlang.conf.5
MANCOMPRESSED=	no

.include <bsd.port.mk>
