#!/bin/sh

!!PREFIX!!/bin/erl -pa !!PREFIX!!/lib/erlang/lib/esdl/ebin:!!PREFIX!!/libexec/wings/ebin -run wings_start start_halt

exit 0
