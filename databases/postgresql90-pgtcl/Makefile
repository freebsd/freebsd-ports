# $FreeBSD$

WANT_PGSQL_VER=	90
PKGNAMESUFFIX=	-postgresql${WANT_PGSQL_VER}

CONFLICTS=	pgtcl-[0-9]* pgtcl-postgresql9[12]-[0-9]*

MASTERDIR=	${.CURDIR}/../pgtcl

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
