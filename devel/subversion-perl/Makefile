# New ports collection makefile for:   subversion-perl
# Date Created:                6 February 2004
# Whom:                        Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PKGNAMESUFFIX=	-perl

MAINTAINER=	autrijus@autrijus.org
COMMENT=	Version control system with Perl bindings

MASTERDIR=	${.CURDIR}/../../devel/subversion
PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist

BROKEN=		Incorrectly installs a perllocal.pod file

WITH_PERL=	yes

.include "${MASTERDIR}/Makefile"
