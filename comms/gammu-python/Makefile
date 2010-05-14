# New ports collection makefile for:	comms/gammu-python
# Date created:				14 May 2010
# Whom:					bsam
#
# $FreeBSD$
#

PORTREVISION=	1
PKGNAMESUFFIX=		-python

CONFLICTS=		gammu-[1-9]* gammu-devel-[1-9]*

WITH_PYTHON_GAMMU=	yes

MASTERDIR=		${.CURDIR}/../gammu

post-install:
	@${PYTHON_CMD} ${PYTHON_SITELIBDIR}/${PORTNAME}/__init__.py


.include "${MASTERDIR}/Makefile"
