# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>
# $FreeBSD$

PKGNAMESUFFIX=	-rails41

DEPRECATED=	Rails 4.1 is no longer supported - please switch to Rails 4.2
EXPIRATION_DATE=	2016-03-31

RUN_DEPENDS=	rubygem-actionpack41>=4.1.12:${PORTSDIR}/www/rubygem-actionpack41 \
		rubygem-activesupport41>=4.1.12:${PORTSDIR}/devel/rubygem-activesupport41 \
		rubygem-sprockets3>=3.0.3:${PORTSDIR}/devel/rubygem-sprockets3

MASTERDIR=	${.CURDIR}/../rubygem-sprockets-rails

.include "${MASTERDIR}/Makefile"
