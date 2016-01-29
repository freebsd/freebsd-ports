# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>
# $FreeBSD$

PKGNAMESUFFIX=	41

DEPRECATED=	Rails 4.1 is no longer supported - please switch to Rails 4.2
EXPIRATION_DATE=	2016-03-31

RUN_DEPENDS=	rubygem-coffee-script>=2.2.0:${PORTSDIR}/devel/rubygem-coffee-script \
		rubygem-railties41>=4.1.12:${PORTSDIR}/www/rubygem-railties41

MASTERDIR=	${.CURDIR}/../rubygem-coffee-rails4

.include "${MASTERDIR}/Makefile"
