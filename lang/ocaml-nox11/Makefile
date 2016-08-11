# Created by: Eugene Ossintsev
# $FreeBSD$

PORTNAME=	ocaml-nox11
CATEGORIES=	lang

MAINTAINER=	michael.grunewald@laposte.net
COMMENT=	Objective Caml compiler and programming environment (no X11)

BROKEN_powerpc64=	Does not build

MASTERDIR=	${.CURDIR}/../ocaml

CONFLICTS=	metaocaml-[0-9]* ocaml-[0-9]* ocaml-notk-[0-9]*

OPTIONS_EXCLUDE=TK X11

SFX=		-nox11

.include "${MASTERDIR}/Makefile"
