#!/bin/sh

# Contributed by Ralf van der Enden <tremere@cainites.net>
# Public domain.

# Print a list of all installed ports by origin with flavour.
# This is similar to pkg info -qoa, but prints a flavour if the
# package has one.

sqlite3 /var/db/pkg/local.sqlite \
	"select origin || coalesce('@' || (
		select t4.annotation as annotation
		from packages t1
		    inner join pkg_annotation t2 on t1.id = t2.package_id
		    inner join annotation t3 on t2.tag_id = t3.annotation_id
			and t3.annotation = 'flavor'
		    inner join annotation t4 on t2.value_id = t4.annotation_id
			and t2.tag_id = t3.annotation_id
			and t3.annotation = 'flavor'
		where t1.origin = t0.origin), '')
	from packages t0;"
