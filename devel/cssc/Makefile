# New ports collection makefile for:    CSSC
# Version required:     0.10beta.pl1
# Date created:         31 Mar 1999
# Whom:                 Oliver Fromme
#
# $FreeBSD$
#

DISTNAME=	CSSC-0.10beta.pl1
PKGNAME=	cssc-0.10b.1
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/gnu/CSSC/

MAINTAINER=	olli@fromme.com

GNU_CONFIGURE=	yes
MAN1=		sccs.1

post-install:
	@strip ${PREFIX}/bin/sccs
	@for FILE in ${PREFIX}/libexec/cssc/*; do \
	    if file $$FILE | ${GREP} -q 'not stripped'; then \
		strip $$FILE; \
	    fi; \
	done
	@install-info ${PREFIX}/info/cssc.info ${PREFIX}/info/dir

.include <bsd.port.mk>
